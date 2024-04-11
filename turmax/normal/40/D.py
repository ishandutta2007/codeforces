n=int(input())
x=2
y=13
if(n==2):
    print("YES\n1\n1\n0")
    exit(0)
if(n==13):
    print("YES\n1\n2\n0")
    exit(0)
arr=[]
for i in range(1300):
    arr.append([])
arr[1].append(13)
arr[0].append(2)
for i in range(600):
    y1=y
    x1=x 
    for j in range(600):
        arr[i+j+2].append(y1)
        x1*=12
        x1,y1=y1,x1
    x=(13*y-12*x)
    x,y=y,x
res1=[]
res2=[]
for i in range(1300):
    for k in arr[i]:
        if(k==n):
            res1.append(i)
            for u in arr[i]:
                if(u!=n):
                    res2.append(u)
if(len(res1)==0):
    print("NO")
    exit(0)
else:
    print("YES")
    res1.sort()
    res3=[]
    for i in range(len(res1)):
        if(i==0 or res1[i]!=res1[i-1]):
            res3.append(res1[i])
    res1=res3
    print(len(res1))
    for u in res1:
        print(u,end=" ")
    print()
    res2.sort()
    res3=[]
    for i in range(len(res2)):
        if(i==0 or res2[i]!=res2[i-1]):
            res3.append(res2[i])
    res2=res3
    o=min(1000,len(res2))
    print(o)
    for i in range(o):
          print(res2[i],end=" ")