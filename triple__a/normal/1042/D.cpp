#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const ld eps=1e-10;
const ll inf=1e18;
const int MAXN = 500007;
 
ll n, t, ans;
 
ll A[MAXN];
ll B[MAXN];
 
void merge(int l,int mid,int r){
    for (int i=l; i<mid; i++){
    	B[i]=A[i];
	}
	B[mid]=inf;
	for (int i=mid; i<r; i++){
    	B[i+1]=A[i];
	}
	B[r+1]=inf;
	int i=l, j=mid+1;
    for (int k=l; k<r; k++){
		if (B[i]<=B[j]) A[k]=B[i++];
		else A[k]=B[j++];
    }
}
 
void Sort(int l,int r){
	if (r-l<2) return ;
    int mid=(l+r+1)/2;
	Sort(l,mid);
	Sort(mid,r);
	for (int i=l; i<mid; i++){
		ans+=(r-(upper_bound(A+mid, A+r, A[i]+t)-A));
	}
	merge(l, mid, r);
}
 
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	cin>>n>>t;
	t=-t;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		A[i]=-A[i];
		A[i]+=A[i-1];
	}
	Sort(0, n+1);
	cout<<ans<<endl;
	
	return 0;
}