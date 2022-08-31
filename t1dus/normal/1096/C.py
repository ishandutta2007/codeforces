for _ in range(int(input())):
    n = int(input())
    for i in range(1,361): # i is number of sides in polygon
        x = 180/i # x is smallest angle in polygon
        if n%x == 0:
            y = n//x
            # print(n,x,y)
            if(y < i-1):
                print(i)
                break
    else:
        print(-1)