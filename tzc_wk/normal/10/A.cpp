#include <bits/stdc++.h>
using namespace std;
int n,p1,p2,p3,t1,t2,ans=0,l[105],r[105];
int main(){
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	for(int i=0;i<n;i++){
		cin>>l[i]>>r[i];
        ans+=(r[i]-l[i])*p1;
        if(i>0){
            if(l[i]-r[i-1]>t1){
                ans+=t1*p1;
                int t=l[i]-r[i-1]-t1;
                if(t>t2)
                {
                    ans+=t2*p2;
                    ans+=(t-t2)*p3;
                }
                else
                    ans+=t*p2;
            }
            else
                ans+=(l[i]-r[i-1])*p1;
        }
	}
	cout<<ans<<endl;
	return 0;
}