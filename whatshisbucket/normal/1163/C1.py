n=int(input())
coords=[]
for i in range(n):
    coords.append(tuple(map(int,input().split())))
slopes={}
for i in range(n):
    for j in range(i+1,n):
        x1,y1=coords[i][0],coords[i][1]
        x2,y2=coords[j][0],coords[j][1]
        if x1==x2:
            slope="inf"
            mark=x1
        else:
            slope=round((y2-y1)/(x2-x1),12)
            mark=round(y1-x1*slope,7)
        if slope in slopes:
            slopes[slope].add(mark)
        else:
            slopes[slope]={mark}
tot=sum(len(slopes[guy]) for guy in slopes)
sumi=0
for guy in slopes:
    a=len(slopes[guy])
    sumi+=a*(tot-a)
print(sumi//2)