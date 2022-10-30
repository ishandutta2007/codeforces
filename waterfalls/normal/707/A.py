n,m = map(int,input().split())
color = False
for i in range(n):
    s = input()
    if 'C' in s or 'M' in s or 'Y' in s:
        color = True
print('#Color' if color else '#Black&White')