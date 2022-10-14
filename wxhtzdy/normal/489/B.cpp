#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],b[N],res=0;
map<int,int> cnt;
int main(){
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]),cnt[a[i]]++;
    scanf("%i",&m);
    for(int i=0;i<m;i++)scanf("%i",&b[i]);
    sort(b,b+m);
    for(int i=0;i<m;i++){
        if(cnt[b[i]-1]>0)cnt[b[i]-1]--,res++;
        else{
            if(cnt[b[i]]>0)cnt[b[i]]--,res++;
            else{
                if(cnt[b[i]+1]>0)cnt[b[i]+1]--,res++;
            }
        }
    }
    printf("%i",res);
}