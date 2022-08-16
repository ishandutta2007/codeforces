powers = [1,2,4]
for i in range(3,50):
    if i == 13:
        powers.append(8092)
    else:
        powers.append(2*powers[i-1])
print(powers[int(input())])