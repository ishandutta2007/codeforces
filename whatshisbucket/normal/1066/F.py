def distance(a,b):
    return(abs(a[0]-b[0])+abs(a[1]-b[1]))
n=int(input())
keys=[]
for i in range(n):
    keys.append(tuple(map(int,input().split())))
dict={}
levels=[]
for key in keys:
    level=max(key)
    if level not in dict:
        levels.append(level)
        dict[level]=[key,key]
    else:
        if distance(key,(0,level))<distance(dict[level][0],(0,level)):
            dict[level]=[key,dict[level][1]]
        if distance(key,(level,0))<distance(dict[level][1],(level,0)):
            dict[level]=[dict[level][0],key]
levels.sort()
left=0
right=0
leftpoint=(0,0)
rightpoint=(0,0)
for level in levels:
    r=distance(dict[level][1],dict[level][0])
    newright=min(right+distance(rightpoint,dict[level][0])+r,left+distance(leftpoint,dict[level][0])+r)
    newleft=min(left+distance(leftpoint,dict[level][1])+r,right+distance(rightpoint,dict[level][1])+r)
    leftpoint=dict[level][0]
    rightpoint=dict[level][1]
    left,right=(newleft,newright)
print(min(left,right))