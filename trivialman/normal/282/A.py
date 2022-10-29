n = list(map(int,input().split()))[0]
x = 0
for i in range(n):
    str0 = input()
    if(str0[1]=='+'):
        x+=1
    else:
        x-=1
print(x)