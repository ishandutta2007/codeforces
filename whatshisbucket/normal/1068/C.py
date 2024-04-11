n,m=map(int,input().split())
harmonies=[]
for i in range(m):
    harmonies.append(list(map(int,input().split())))
spots=[]
for i in range(n):
    yourspots=[]
    for j in range(m):
        if i+1 in harmonies[j]:
            yourspots.append((i+1,j+1))
    yourspots.append((i+1,10000-i))
    spots.append(yourspots)
for i in range(n):
    print(len(spots[i]))
    for j in range(len(spots[i])):
        print(str(spots[i][j][0]),str(spots[i][j][1]))