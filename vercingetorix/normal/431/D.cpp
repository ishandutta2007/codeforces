#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);

}

long long v(long long x, int k){
    if(k==0) return 1;
    if(x==1){
        if(k==1) return 1;
        else return 0;
    }
    if(x==0) return 0;
    long long ans=0;
    long long d=1;
    int g=0;
    while(d<=(x/2)){
        d*=2;
        g++;
    }
    long long c=1;
    int h=k;
    while(h<g){
        long long gc=gcd(h+1,h+1-k);
        c=(c/((h+1-k)/gc))*((h+1)/gc);
        h++;
    }
    if(g<k) c=0;
    return c+v(x-d,k-1);

}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
 int n;
 long long maxm=1000000000000000000;
 long long m;
 int k;
 int ans=0;
 cin >> m >> k;
 int l=k-1;
 long long c=1;
 if(m==0){
     cout<<1;
     return 0;
 }
 if(k==1){
     cout<<1;
     return 0;
}
  long long deg=1;
  for(int i=0;i<k-1;i++) deg*=2;
 while((c<m)&&((deg*2)<maxm)){
     double x=c;
     double y=m;
     x*=(double)(l+1)/(double)(l-k+2);
     if(x>(y+.2)) break;
     long long gc=gcd(l+1,l-k+2);
     //c=(long long)(x+.2);
     c=(c/((l-k+2)/gc))*((l+1)/gc);
     l++;
     deg*=2;
}
 long long rest=m-c;

 long long x=0;
 long long xans=-1;
 //for(int i=0;i<l;i++) deg*=2;
 if(rest==0){
     cout<<deg;
     return 0;
 }
 long long t=1;
 for(int i=0;i<l;i++){
     t*=2;
    
 }
 long long f=1;
 while(deg>1){
     deg/=2;
     x+=f*deg;
     long long cur=v(x, k-2);
     if(cur>=rest) f=-1;
     if(cur<rest) f=1;
     if(cur==rest) {
         xans=x;
     }
 }
 
 cout<<t+xans+1;
 //cout<<endl;
 //cout<<v(2*981546175132942859, 31)-v(981546175132942859, 31)<<endl;
 //cout<<v(2*981546175132942729, 31)-v(981546175132942729, 31)<<endl;


//cout<<ans;
  return 0;
}