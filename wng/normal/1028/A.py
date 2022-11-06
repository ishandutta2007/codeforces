n,m=[int(k) for k in raw_input().split(" ")]
s=[]
for i in range(n):
    s+=[raw_input()]


nb=0
x=0
y=0
for i in range(n):
    for j in range(m):
        if s[i][j]=="B":
            nb+=1
            x+=i
            y+=j


print x/nb+1,y/nb+1