#include"iostream"
int main() {
    long long l;
    std::cin>>l;
    while(l%3==0)l/=3;
    std::cout<<(l/3+1);
}