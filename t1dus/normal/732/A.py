n,k = map(int,input().split())
n %= 10
for i in range(1,10):
    y = (n*i)%10
    if y == k or y==0:
        print(i)
        break