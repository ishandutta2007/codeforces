#include <iostream>
using namespace std;
int a[105],b[105];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++) if(a[i]&&!b[i]) ++cnt1;
	for(int i=1;i<=n;i++) if(b[i]&&!a[i]) ++cnt2;
	if(!cnt1) puts("-1");
	else cout << (cnt2)/cnt1+1;
	return 0;
}