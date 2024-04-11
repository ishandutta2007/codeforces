n = int(input())
for i in range(n):
    str0 = input()
    l = len(str0)
    if(l<=10):
        print(str0)
    else:
        print(str0[0]+str(l-2)+str0[l-1])