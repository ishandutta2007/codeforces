#include <bits/stdc++.h>
using namespace std;
int a,b,ans;
int main(){
	cin>>a>>b;
    int c=__gcd(a,b);
    a/=c,b/=c;
    while(a>1){
        int add=0;
        if(a%5==0)	a/=5,add++;
        if(a%3==0)	a/=3,add++;
        if(a%2==0)	a/=2,add++;
        if(!add)	return puts("-1"),0;
        ans+=add;
    }
    while(b>1){
		int add=0;
		if(b%5==0)	b/=5,add++;
		if(b%3==0)	b/=3,add++;
		if(b%2==0)	b/=2,add++;
		if(!add)	return puts("-1"),0;
		ans+=add;
	}
	cout<<ans<<endl;
}