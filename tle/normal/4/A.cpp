//zzq
#include <iostream>
#include <iterator>
main(){int tmp=*std::istream_iterator<int>(std::cin); if(tmp<=2||tmp%2) std::cout<<"NO"; else std::cout<<"YES";}