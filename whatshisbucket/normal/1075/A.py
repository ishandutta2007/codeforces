n=int(input())
a,b=map(int,input().split())
white=abs(a-1)+abs(b-1)
black=abs(n-a)+abs(n-b)
if white<=black:
    print("White")
else:
    print("Black")