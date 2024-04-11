read = lambda : map(int, input().split())
n = int(input())
t = list(read())
def calc():
    if t[0] > 15 :
        return 15
    t.append(90)
    for i in range(n):
        if t[i] + 15 < t[i + 1] :
            return t[i] + 15
    return 90
print(calc())