// ...
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numStation, time, capacity; std::cin>>numStation>>time>>capacity;
	struct Station{
		int start, change, maximum;
	};
	std::vector<Station> stations(numStation);
	for(auto& [start, change, maximum]: stations){
		std::cin>>start>>change>>maximum;
		assert(start<=maximum); assert(change<=maximum);
	}

	while(true){
		if(stations.empty()){
			std::cout<<"0\n";
			return 0;
		}

		auto const [start, change, maximum]=stations.back();
		if(start+change*(int64_t)time<=maximum){
			stations.pop_back();
			--numStation;
		}else
			break;
	}

	std::vector<std::vector<int64_t>> f(numStation, std::vector<int64_t>(time+1));
	// f[i][time0]=minimum number of trains (0, 0,..., [i]=0) -> (0, 0,...,[i-1]= 0,[i]= any)
	// with time0 additions
	// never exceed [i] before time0 additions
	// or INT64_MAX, if there's none

	//int64_t startPrefix=0;
	int64_t changePrefix=0;
	for(int station=0; station<numStation; ++station){
		auto const [start, change, maximum]=stations[station];
		changePrefix+=change;
		//auto const startBefore=startPrefix; startPrefix+=start;

		f[station][0]=0;

		for(int time0=1; time0<=time; ++time0){
			auto& cur=f[station][time0]=INT64_MAX;
			if((int64_t)time0*change<=maximum){ // I suppose this is not necessary? last==0 always satisfy.
				if(station==0) cur=0;
				else if(f[station-1][time0]!=INT64_MAX)
					cur=((changePrefix-change)*time0+capacity-1)/capacity;
			}
			for(int last=0; last<time0;++last){
				// last=last time <time0 such that stations [0..i] are empty
				auto const numTrainBeforeY=f[station][last];
				if(numTrainBeforeY==INT64_MAX) continue;
				auto const y=changePrefix*last-capacity*numTrainBeforeY;
				assert(y>-capacity); assert(y<=maximum);
				if(y<0) continue; // exceed [i] at last<time0 already, invalid

				if(
						(station==0 or f[station-1][time0-last]!=INT64_MAX)
						and
						y%capacity+int64_t(time0-last)*change<=maximum){

					auto const delta=maximum-y%capacity-int64_t(time0-last)*change;
					assert(delta>=0);

					auto const y1=std::min(y, y%capacity+delta/capacity*capacity);
					assert((y-y1)%capacity==0);

					auto const numTrainBeforeY1=numTrainBeforeY+(y-y1)/capacity;

					assert(y1+int64_t(time0-last)*change<=maximum);
					cur=std::min(cur,
							numTrainBeforeY1+((changePrefix-change)*(time0-last)+capacity-1)/capacity
							);
				}
			}
		}
	}

	std::vector<std::vector<int64_t>> g(numStation, std::vector<int64_t>(time+1));
	// g[i][time0]=minimum number of trains (stations[0].start ..= stations[i].start) -> (0, 0,...,[i-1]= 0,[i]= any)
	// with time0 additions
	// never exceed [i] before time0 additions
	// or INT64_MAX, if there's none

	// (seriously, copy and paste code is not a good idea)
	changePrefix=0;
	int64_t startPrefix=0;
	for(int station=0; station<numStation; ++station){
		auto const [start, change, maximum]=stations[station];
		changePrefix+=change;
		auto const startBefore=startPrefix;
		startPrefix+=start;

		g[station][0]=(startBefore+capacity-1)/capacity;

		for(int time0=1; time0<=time; ++time0){
			auto& cur=g[station][time0]=INT64_MAX;
			if(start+(int64_t)time0*change<=maximum){
				if(station==0) cur=0;
				else if(g[station-1][time0]!=INT64_MAX)
					cur=(startPrefix-start+(changePrefix-change)*time0+capacity-1)/capacity;
			}

			for(int last=0; last<time0;++last){
				// last=last time <time0 such that stations [0..i] are empty
				auto const numTrainBeforeY=g[station][last];
				if(numTrainBeforeY==INT64_MAX) continue;
				auto const y=startPrefix+changePrefix*last-capacity*numTrainBeforeY;
				assert(y>-capacity); assert(y<=maximum);
				if(y<0) continue; // exceed [i] at last<time0 already, invalid

				if(
						(station==0 or f[station-1][time0-last]!=INT64_MAX)
						and
						y%capacity+int64_t(time0-last)*change<=maximum){

					auto const delta=maximum-y%capacity-int64_t(time0-last)*change;
					assert(delta>=0);

					auto const y1=std::min(y, y%capacity+delta/capacity*capacity);
					assert((y-y1)%capacity==0);

					auto const numTrainBeforeY1=numTrainBeforeY+(y-y1)/capacity;

					assert(y1+int64_t(time0-last)*change<=maximum);
					cur=std::min(cur,
							numTrainBeforeY1+((changePrefix-change)*(time0-last)+capacity-1)/capacity
							);
				}
			}
		}
	}

	std::vector<std::vector<int64_t>> h(numStation, std::vector<int64_t>(time+1));
	// h[i][time0]=minimum number of trains (0 ..= [i]=0) -> any
	// with time0 additions
	// never exceed [i] (there's no point in exceeding [i] after time0 additions because the target is any
	// or INT64_MAX, if there's none
	changePrefix=0;
	for(int station=0; station<numStation; ++station){
		auto const [start, change, maximum]=stations[station];
		changePrefix+=change;

		h[station][0]=0;

		for(int time0=1; time0<=time; ++time0){
			auto& cur=h[station][time0]=INT64_MAX;
			if(change*(int64_t)time0<=maximum){
				cur=station==0 ? 0: h[station-1][time0];
			}

			for(int last=0; last<time0;++last){
				// last=last time <time0 such that stations [0..i] are empty
				auto const numTrainBeforeY=f[station][last];
				if(numTrainBeforeY==INT64_MAX) continue;
				auto const y=changePrefix*last-capacity*numTrainBeforeY;
				assert(y>-capacity); assert(y<=maximum);
				if(y<0) continue; // exceed [i] at last already, invalid

				if(
						(station==0 or h[station-1][time0-last]!=INT64_MAX)
						and
						y%capacity+int64_t(time0-last)*change<=maximum){

					auto const delta=maximum-y%capacity-int64_t(time0-last)*change;
					assert(delta>=0);

					auto const y1=std::min(y, y%capacity+delta/capacity*capacity);
					assert((y-y1)%capacity==0);

					auto const numTrainBeforeY1=numTrainBeforeY+(y-y1)/capacity;

					assert(y1+int64_t(time0-last)*change<=maximum);
					cur=std::min(cur,
							numTrainBeforeY1+(station==0 ? 0: h[station-1][time0-last])
							);
				}
			}
		}
	}

	std::vector<int64_t> j(time+1);
	// j[time0]=similar to h[numStation-1][time0], but might exceed
	j[0]=0;
	for(int time0=1; time0<=time; ++time0){
		j[time0]=h[numStation-1][time0];
		for(int time1=1; time1<=time0;++time1){
			if(f[numStation-1][time1]!=INT64_MAX)
				j[time0]=std::min(j[time0], j[time0-time1]+
						(changePrefix*time1+capacity-1)/capacity);
		}
		assert(j[time0]!=INT64_MAX);
	}

	int64_t result=INT64_MAX;
	for(int time0=0; time0<=time; ++time0){
		auto const numTrainBeforeY=g[numStation-1][time0];
		if(numTrainBeforeY==INT64_MAX) continue;
		auto const y=time0*changePrefix+startPrefix-numTrainBeforeY*capacity;
		assert(y>-capacity); assert(y<=stations.back().maximum);

		// in case there's no train that exceeds the last station
		// let `time0` be the last time for the last station to be changed
		// (or something like that)
		if(y>=0){
			auto const delta=
				stations.back().maximum-stations.back().change*int64_t(time-time0)-y%capacity;
			if(delta>=0){
				auto const y1=std::min(y, y%capacity+delta/capacity*capacity);
				assert((y-y1)%capacity==0);

				auto const numTrainBeforeY1=numTrainBeforeY+(y-y1)/capacity;

				assert(y1+int64_t(time-time0)*stations.back().change<=stations.back().maximum);

				if(numStation==1)
					result=std::min(result, numTrainBeforeY1);
				else if(h[numStation-2][time-time0]!=INT64_MAX)
					result=std::min(result, numTrainBeforeY1+h[numStation-2][time-time0]);
			}
		}

		// in case there is...
		result=std::min(result,
			(time0*changePrefix+startPrefix+capacity-1)/capacity+
			j[time-time0]);
	}

	std::cout<<result<<'\n';
}