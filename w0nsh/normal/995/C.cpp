#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#define PR std::pair
#define X first
#define Y second

int n;
std::vector<bool> sign;
std::vector<std::pair<double, double> > vec;
std::vector<std::vector<int> > which;

void reduce(){
	if(vec.size() == 2){
		if(std::pow(vec[0].X+vec[1].X, 2)+std::pow(vec[0].Y+vec[1].Y, 2) < std::pow(vec[0].X-vec[1].X, 2)+std::pow(vec[0].Y-vec[1].Y, 2))
			vec[0] = {vec[0].X+vec[1].X, vec[0].Y+vec[1].Y};
		else{
			vec[0] = {vec[0].X-vec[1].X, vec[0].Y-vec[1].Y};
			for(auto ind : which[1]) sign[ind] = !sign[ind];
		}
		vec.resize(1);
		return;
	}
	int rozp = (vec.size()/3)*3;
	for(int i = 0; i < rozp; i+=3){
		bool signs[2] = {true, true};
		double bestX = 1e8;
		double bestY = 1e8;
		if(std::pow((vec[i].X+vec[i+1].X+vec[i+2].X), 2)+std::pow((vec[i].Y+vec[i+1].Y+vec[i+2].Y), 2) < std::pow(bestX, 2)+std::pow(bestY, 2)){
			bestX = (vec[i].X+vec[i+1].X+vec[i+2].X);
			bestY = (vec[i].Y+vec[i+1].Y+vec[i+2].Y);
			signs[0] = signs[1] = true;
//			std::cout << "opcja 1 " << bestX << " " << bestY << std::endl; 
		}
		if(std::pow((vec[i].X+vec[i+1].X-vec[i+2].X), 2)+std::pow((vec[i].Y+vec[i+1].Y-vec[i+2].Y), 2) < std::pow(bestX, 2)+std::pow(bestY, 2)){
			bestX = (vec[i].X+vec[i+1].X-vec[i+2].X);
			bestY = (vec[i].Y+vec[i+1].Y-vec[i+2].Y);
			signs[0] = true;
			signs[1] = false;
//			std::cout << "opcja 2 " << bestX << " " << bestY << std::endl; 
		}
		if(std::pow((vec[i].X-vec[i+1].X-vec[i+2].X), 2)+std::pow((vec[i].Y-vec[i+1].Y-vec[i+2].Y), 2) < std::pow(bestX, 2)+std::pow(bestY, 2)){
			bestX = (vec[i].X-vec[i+1].X-vec[i+2].X);
			bestY = (vec[i].Y-vec[i+1].Y-vec[i+2].Y);
			signs[0] = signs[1] = false;
//			std::cout << "opcja 3 " << bestX << " " << bestY << std::endl; 
		}
		if(std::pow((vec[i].X-vec[i+1].X+vec[i+2].X), 2)+std::pow((vec[i].Y-vec[i+1].Y+vec[i+2].Y), 2) < std::pow(bestX, 2)+std::pow(bestY, 2)){
			bestX = (vec[i].X-vec[i+1].X+vec[i+2].X);
			bestY = (vec[i].Y-vec[i+1].Y+vec[i+2].Y);
			signs[0] = false;
			signs[1] = true;
//			std::cout << "opcja 4 " << bestX << " " << bestY << std::endl; 
		}
		if(!signs[0])
			for(auto ind : which[i+1]) sign[ind] = !sign[ind];
		if(!signs[1])
			for(auto ind : which[i+2]) sign[ind] = !sign[ind];
		vec[i/3] = {bestX, bestY};
		which[i/3].clear();
		for(auto ind : which[i]) which[i/3].push_back(ind);
		for(auto ind : which[i+1]) which[i/3].push_back(ind);
		for(auto ind : which[i+2]) which[i/3].push_back(ind);
	}
	while(rozp < vec.size()){
		vec[rozp/3 + rozp%3] = vec[rozp];
		which[rozp/3 + rozp%3] = which[rozp];
		rozp++;
	}
	vec.resize(rozp/3 + rozp%3);
	which.resize(rozp/3 + rozp%3);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	sign.resize(n, true);
	for(int i = 0; i < n; ++i){
		double a, b;
		std::cin >> a >> b;
		vec.push_back({a, b});
		which.push_back(std::vector<int>{i});
	}
	while(vec.size() > 1){
		reduce();
	}
	for(int i = 0; i < n; ++i){
		std::cout << (sign[i] ? 1 : -1) << " ";
	}
	std::cout << "\n";
	return 0;
}