x,t,a,b,da,db=map(int,input().split())
if x==0:
    print("YES")
    exit()
for ta in range(t):
    for tb in range(t):
        if x==a-ta*da or x==b-tb*db or x==a-ta*da+b-tb*db:
            print("YES")
            exit()
print("NO")