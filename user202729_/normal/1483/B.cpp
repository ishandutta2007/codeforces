#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	// ...
	int numSong; std::cin>>numSong;
	struct Song{int value /* genre */, index;};
	std::deque<std::deque<Song>> songs(numSong);
	for(int i=0; i<numSong; ++i){
		songs[i].push_back({});
		songs[i][0].index=i;
		std::cin>>songs[i][0].value;
	}

	auto const merge=[&](
			std::deque<Song> a,
			std::deque<Song> b
			){
		if(a.size()<b.size()){
			std::for_each(a.rbegin(), a.rend(), [&](auto const& it){b.push_front(it);});
			return std::move(b);
		}else{
			for(auto it: b) a.push_back(it);
			return std::move(a);
		}
	};

	std::vector<int> deleted;
	while(not songs.empty()){

		auto tmp=std::move(songs[0]); songs.pop_front();

		if(not songs.empty() and std::gcd(songs.back().back().value, tmp[0].value)!=1){
			songs.back()=merge(std::move(songs.back()), std::move(tmp));
		}else{
			songs.push_back(std::move(tmp));
		}

		if(std::gcd(songs.back().back().value, songs[0][0].value)==1){
			deleted.push_back(songs[0][0].index); songs[0].pop_front();
			if(songs[0].empty()) songs.pop_front();
		}else if(songs.size()==1){
			break;
		}
	}

	std::cout<<deleted.size();
	for(auto it: deleted) std::cout<<' '<<it+1;
	std::cout<<'\n';
}