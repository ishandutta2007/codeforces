#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
string s;
int mi[2000010];
int ma[2000010];
int d[1000010];
int h = sizeof(int)*8;
void apply(int p,int value){
    mi[p]+=value;
    ma[p]+=value;
    if(p<n) d[p]+=value;
}
void build(int p){
    while(p>1){
        p/=2;
        mi[p] = min(mi[2*p],mi[2*p+1])+d[p];
        ma[p] = max(ma[2*p],ma[2*p+1])+d[p];
    }
}
void push(int p){
    for(int s=h;s>0;s--){
        int i = p>>s;
        if(d[i]!=0){
            apply(2*i,d[i]);
            apply(2*i+1,d[i]);
            d[i] = 0;
        }
    }
}
void inc(int l,int r,int value){
    l+=n; r+=n;
    int l0 = l, r0 = r;
    while(l<r){
        if(l%2==1){
            apply(l,value);
            l++;
        }
        if(r%2==1){
            apply(r-1,value);
        }

        l/=2; r/=2;
    }
    build(l0);
    build(r0-1);
}
pair<int,int> query(int l,int r){
    l+=n; r+=n;
    push(l);
    push(r-1);
    int retMin = 1e9;
    int retMax = -1e9;
    while(l<r){
        if(l%2==1){
            retMin = min(retMin,mi[l]);
            retMax = max(retMax,ma[l]);
            l++;
        }
        if(r%2==1){
            retMin = min(retMin,mi[r-1]);
            retMax =max(retMax,ma[r-1]);
        }

        l/=2; r/=2;
    }
    return {retMin,retMax};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>> n;
    cin >> s;
    int cursor =0;
    int arr[n];
    int ans[n];
    int a[n];
    int sum = 0;
    memset(arr,0,sizeof(arr));
    memset(a,0,sizeof(a));
    //n+1 leaves...
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            if(a[cursor] == 0){
                inc(cursor,n,1);
                sum++;
            }
            else if(a[cursor]==-1){
                inc(cursor,n,2);
                sum+=2;
            }
            a[cursor] = 1;
        }
        else if(s[i]==')'){
            if(a[cursor]==0){
                inc(cursor,n,-1);
                sum--;
            }
            else if(a[cursor]==1){
                inc(cursor,n,-2);
                sum-=2;
            }
            a[cursor] = -1;
        }
        else if(s[i]=='R') cursor++;
        else if(s[i]=='L'){
            if(cursor==0){
            }
            else cursor--;
        }
        else{
            if(a[cursor]==1){
                inc(cursor,n,-1);
                sum--;
            }
            else if(a[cursor]==-1){
                inc(cursor,n,1);
                sum++;
            }
            a[cursor] = 0;
        }

        pair<int, int> k = query(0,n);
        if(k.first<0 || sum!=0){
            ans[i] = -1;
        }
        else{
            ans[i] = k.second;
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    

}