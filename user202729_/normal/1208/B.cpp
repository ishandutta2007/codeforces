#include<iostream>
#include<vector>
#include<unordered_set>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n);for(int& x:a)std::cin>>x;

	int l=0,r=n;
	std::unordered_set<int> t;t.reserve(n); // non deleted elements

	while(r>0){
		if(t.count(a[r-1]))
			break;
		t.insert(a[r-1]);
		--r;
	}

	int ans=r;
	while(ans>0&&l<n){
		int newinsert=a[l];
		if(t.count(newinsert)){
			while(r<n){
				if(a[r]==newinsert){
					++r;
					++l;
					goto inserted;
				}
				t.erase(a[r]);
				++r;
			}
			break;
		}else{
			t.insert(newinsert);
			++l;
		}

inserted:
		ans=std::min(ans,r-l);
	}

	std::cout<<ans<<'\n';
}