#include <bits/stdc++.h>
using namespace std;
#define int long long
string S;
int b,s,c;
int nb,ns,nc,pb,ps,pc,a;
bool check(int x){
	int res=0;
    if(x*b>=nb)	res=res+(x*b-nb)*pb;
    if(x*c>=nc)	res=res+(x*c-nc)*pc;
    if(x*s>=ns)	res=res+(x*s-ns)*ps;
    return res<=a;
}
signed main(){
    cin>>S;
    for(int i=0;i<S.size();i++){
    	if(S[i]=='B')		b++;
    	else if(S[i]=='S')	s++;
    	else				c++;
	}
	cin>>nb>>ns>>nc>>pb>>ps>>pc>>a;
    int l=0,r=1e13,ans;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))	ans=mid,l=mid+1;
        else			r=mid-1;
    }
    cout<<ans<<endl;
}