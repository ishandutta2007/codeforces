#include<bits/stdc++.h>
using namespace std;
long long b[200005];
int n;
long long sum(long long x){
    if(x==0){
        return 0;
    }
        long long pas=0;
        while(x>0){
            pas+=b[x];

            x=x&(x-1);
        }
        return pas;
}
void update(long long x, long long i){
    while(i<=n){

        b[i]+=x;
        i+=(i&(-i));

    }
}

int main(){

    cin>>n;
    long long s[n+1];
    s[0]=0;
    int p[n+1];
    p[0]=0;
    for(int i=1; i<=n; i++){
        cin>>s[i];
        update(i , i);

    }
    int mid=0;

    for(int i=n; i>0; i--){

       int l=1;
       int r=n;
        while(l!=r){

            mid=(l+r+1)/2;
          //  cout<<l<<r<<mid<<endl;
            if(sum(mid-1)<=s[i]){
                l=mid;
            }else{
                r=mid-1;
            }



        }
        update( -l, l);
   //  cout<<"b[l]: "<<b[l]<<endl;
  /////      cout<<"m: "<<mid<<endl;
  ////     cout<<"l: "<<l;
         p[i]=l;

    }
    for(int i=1; i<=n; i++){
        cout<<p[i]<<" ";
    }

}