s = input()
a = ["Danil", "Olya", "Slava", "Ann", "Nikita"]
cnt = 0
for i in a:
    cnt += s.count(i)
print("YES" if cnt == 1 else "NO")