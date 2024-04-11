n=int(input())
a=list(map(int,input().split()))
down=[]
good=True
for guy in a:
    if len(down)==0:
        down.append(guy)
    elif down[-1]>guy:
        down.append(guy)
    elif down[-1]==guy:
        down.pop()
    else:
        good=False
        break
if not good:
    print("NO")
elif len(down)>1:
    print("NO")
elif len(down)==1 and down[0]!=max(a):
    print("NO")
else:
    print("YES")