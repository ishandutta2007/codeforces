s = input()
a = input().split()
for i in a:
    if i[0] == s[0] or i[1] == s[1]:
        print("YES")
        break
else:
    print("NO")