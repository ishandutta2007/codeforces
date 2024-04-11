for i in range(5):
    a = list(map(int, input().split()))
    if(sum(a)==1):
        for j in range(5):
            if(a[j]==1):
                break
        print(abs(i-2)+abs(j-2))
        break