biggest= 0
g = int(input())
s = input().split()
for b in s:
    count = 0
    for i in b:
        if i == i.upper():count+=1
    if count > biggest:
        biggest = count
print(biggest)