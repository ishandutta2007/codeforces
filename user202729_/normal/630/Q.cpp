#include<iostream>
#include<iomanip>
#include<cmath>

int main(){
	double const PI=std::acos(-1);
	double ans=0;
	for(int i=3;i<=5;++i){
		// assume edge length = 1
		double inner_angle=PI-2*PI/i;
		double center_to_vert_len=0.5/std::cos(inner_angle/2);
		double center_to_edge_len=std::sqrt(center_to_vert_len*center_to_vert_len-0.5*0.5);
		double height=std::sqrt(1-center_to_vert_len*center_to_vert_len);
		double base_area=center_to_edge_len*i/2.;
		double volume=1./3*height*base_area;

		int l;std::cin>>l;
		ans+=l*l*l*volume;
	}
	std::cout<<std::fixed<<std::setprecision(10)<<ans<<'\n';
}