a=raw_input()
b = 0
c = ["Danil", "Olya", "Slava", "Ann", "Nikita"]
for i in xrange(len(a)):
    for d in c:
        if a[i:i+len(d)] == d:
            b += 1
print 'YES' if b == 1 else 'NO'