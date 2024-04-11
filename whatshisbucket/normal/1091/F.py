n=int(input())
l=list(map(int,input().split()))
s=input()
water=0
grass=0
cgrass=0
time=0
seen=False
for i in range(n):
    if s[i]=="G":
        dist=l[i]
        if water>=dist:
            water-=dist
            time+=2*dist
            cgrass+=dist
        else:
            dist-=water
            time+=2*water
            cgrass+=water
            water=0
            time+=3*dist
            grass+=dist
    elif s[i]=="W":
        water+=l[i]
        time+=2*l[i]
        seen=True
    else:
        dist=l[i]
        if water>=dist:
            water-=dist
            time+=2*dist
        else:
            dist-=water
            time+=2*water
            water=0
            if cgrass>=dist:
                cgrass-=dist
                grass+=dist
                time+=3*dist
            else:
                dist-=cgrass
                grass+=cgrass
                time+=3*cgrass
                cgrass=0
                if grass>=dist:
                    grass-=dist
                    time+=3*dist
                else:
                    dist-=grass
                    time+=3*grass
                    grass=0
                    if seen:
                        time+=4*dist
                    else:
                        time+=6*dist
print(time)