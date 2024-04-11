a=list(map(int,input().split()))
print(sum(list(map(lambda x:a[int(x)-1],input()))))