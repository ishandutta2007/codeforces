#include <bits/stdc++.h>
#define LiuYuHan std
using namespace LiuYuHan;
#define LiuYuHanILoveYou ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(12); 
int main(){
#ifdef LiuYuHan20170119FromNFLS
    freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
    LiuYuHanILoveYou
    double l,d,v,g,r;
    cin>>l>>d>>v>>g>>r;
    double ans=0;
    double t1=d/v;
    double f=((int)t1/(int)(r+g))*(r+g);
    if(t1-f<g){
        ans=l/v;
    }else{
        ans=f+g+r+(l-d)/v;
    }
    cout << ans << "\n";
}