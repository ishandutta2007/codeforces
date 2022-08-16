n = int(input())
x = 'a'
for i in range(1,n,2):
    print(x*2,end = '')
    if x == 'a':
        x = 'b'
    else:
        x = 'a'
if n%2:
    print(x)