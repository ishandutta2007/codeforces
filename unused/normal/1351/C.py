for _ in range(int(input())):
    x,y=0,0
    paths=set()
    score=0
    for c in input():
        if c=='E':
            dx,dy=1,0
        elif c=='W':
            dx,dy=-1,0
        elif c=='N':
            dx,dy=0,1
        else:
            dx,dy=0,-1
        p=[(x,y),(x+dx,y+dy)]
        p=tuple(sorted(p))
        if p in paths:
            score+=1
        else:
            score+=5
            paths.add(p)
        x,y=x+dx,y+dy
    print(score)