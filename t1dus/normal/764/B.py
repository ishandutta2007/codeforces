n = int(input())
a = list(map(int,input().split()))
# if n%2 == 0:
#     for i in range(n//2):
#         if i%2 == 0:
#             print(a[-i-1], end = ' ')
#         else:
#             print(a[i], end = ' ')
for i in range(n//2):
    if (i%2 == 0):
        a[i],a[n-i-1] = a[n-i-1],a[i]
for i in a:
    print(i,end= ' ')
print('')