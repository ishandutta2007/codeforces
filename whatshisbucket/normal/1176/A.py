q=int(input())
for u in range(q):
    n=int(input())
    a=0
    while n%2==0:
        a+=1
        n//=2
    while n%3==0:
        a+=2
        n//=3
    while n%5==0:
        a+=3
        n//=5
    if n>1:
        print(-1)
    else:
        print(a)