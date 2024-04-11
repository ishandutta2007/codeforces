num = int(input())
luckyn = []
for i in range(1001):
    if({'4','7'}.issuperset(set(str(i)))):
        luckyn.append(i)

flag = False
for i in luckyn:
    if num%(i)==0:
        flag = True
print('YES' if flag else 'NO')