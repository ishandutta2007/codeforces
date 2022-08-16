print('YES')
for _ in range(int(input())):
    a,b,c,d = map(int,input().split())
    print((2*(a%2))+(b%2)+1)