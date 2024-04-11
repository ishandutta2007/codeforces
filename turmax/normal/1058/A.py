n=int(input())
a=[int(i) for i in input().split()]
d=0
for k in a:
    if(k==1):
        d=1
        print("HARD")
        break
if(d==0):
    print("EASY")