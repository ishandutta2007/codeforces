// https://codeforces.com/problemset/problem/850/A
#include<iostream>
#include<vector>
#include<array>
int main(){
	int n;std::cin>>n;
	if(n>12){std::cout<<"0\n";return 0;}
	std::vector<std::array<int,5>> pts(n);
	for(auto& pt:pts)for(int& x:pt)std::cin>>x;

	std::vector<int> ans;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)if(j!=i)
			for(int k=0;k<j;++k)if(k!=i){
				int dotproduct=0;
				for(int dim=0;dim<5;++dim)
					dotproduct+=(pts[j][dim]-pts[i][dim])*(pts[k][dim]-pts[i][dim]);
				if(dotproduct>0)
					goto point_is_bad;
			}
		ans.push_back(i+1);
point_is_bad:;
	}
	std::cout<<ans.size()<<'\n';
	for(int x:ans)std::cout<<x<<' ';
	std::cout<<'\n';
}