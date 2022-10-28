w,h,k=map(int,input().split())
squares=0
for i in range(k):
    squares+=2*w+2*h-4
    w-=4
    h-=4
print(squares)