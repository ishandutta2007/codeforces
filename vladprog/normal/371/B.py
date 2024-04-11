from math import*

def main():
    R=lambda:map(int,input().split())
    a,b=R()
    d=gcd(a,b)
    a//=d
    b//=d
    ans=0
    while a%2==0:
        a//=2
        ans+=1
    while a%3==0:
        a//=3
        ans+=1
    while a%5==0:
        a//=5
        ans+=1
    while b%2==0:
        b//=2
        ans+=1
    while b%3==0:
        b//=3
        ans+=1
    while b%5==0:
        b//=5
        ans+=1
    if a==1 and b==1:
        print(ans)
    else:
        print(-1)

main()