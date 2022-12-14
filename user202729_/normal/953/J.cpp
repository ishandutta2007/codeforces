#include<iostream>
#include<map>
int main(){
   std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
   int n;std::cin>>n;
   std::map<int,bool>endpt_open;
   while(n-->0){
      int l,r;std::cin>>l>>r;
      while(true){
         auto it=endpt_open.lower_bound(l);

         //larger than all elements
         if(it==endpt_open.end())break;

         if(it->first>r){
            if(it->second)break;//open
            else goto continue_outer;//strictly inside
            //another segment
         }
         
         if(it->second){//is open
            it=endpt_open.erase(it);//now it's a close point
            r=std::max(r,it->first);endpt_open.erase(it);
         }else{//is close. guarantee that the prev element is <l
            it=endpt_open.erase(it);--it;
            l=it->first;endpt_open.erase(it);
         }
      }
      endpt_open[l]=true;endpt_open[r]=false;
      
      continue_outer:
      std::cout<<endpt_open.size()/2<<' ';
   }
   std::cout<<'\n';
}