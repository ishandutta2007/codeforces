a = int(input())
if a==1 or a==2:
    print(-1)
else:
    num = 1
    while a%2==0:
        a//=2
        num*=2
    if a==1:
        print(3*num//4,5*num//4)
    else:
        print(a**2//2*num,(a**2//2+1)*num)