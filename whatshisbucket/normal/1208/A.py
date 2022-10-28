T=int(input())
for _ in range(T):
    a,b,n=map(int,input().split())
    c=a^b
    if n%3==0:
        print(a)
    elif n%3==1:
        print(b)
    else:
        print(c)