#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll f[100009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	//cin.exceptions(cin.failbit);
	int q;cin>>q;
	string fx = "What are you doing at the end of the world? Are you busy? Will you save us?" ;
	string fy = "What are you doing while sending \"";
	string fz = "\"? Are you busy? Will you send \"";
	string fw = "\"?";
	//string xx = "What are you doing while sending \"What are you doing at the end of the world? Are you busy? Will you save us?\"? Are you busy? Will you send \"What are you doing at the end of the world? Are you busy? Will you save us?\"?";
	//cout<<xx.size()<<fy.size()<<sz(fz)<<endl;
	f[0] = 75;
	repA(i,1,55){
		f[i] = 2*f[i-1]+68;
	}
	rep(i,q){
		ll n,k;cin>>n>>k;
		if(f[n]<k&&n<53){
			cout<<'.';
		}
		else{
			{
				
				while(true){
					//cout<<f[n]<<" "<<k<<" "<<n<<endl;
					if(n==0){
						//cout<<k<<endl;
						cout<<fx[k-1]; break;
					}
					if(k<=34){
						cout<<fy[k-1]; break;
					}
					else if(k<=34+f[n-1]||n>=54){
						n--;k-=34;
						continue;
					}
					else if(k<=66+f[n-1]){
						cout<<fz[k-35-f[n-1]]; break;
					}
					else if (k<=66+2*f[n-1])
					{
						//cout<<k<<endl;
						n--;k-=(66+f[n]);continue;
					}
					else{
						cout<<fw[k-67-2*f[n-1]]; break;
					}
				}
			}
		}
	}




	return 0;
}