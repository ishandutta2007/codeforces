import math

t = int(input())

def get_square_numbers(n):
    i = 1
    square_numbers = []
    while i * i <= n:
        square_numbers.append(i * i)
        i += 1
    return square_numbers

def get_cube_numbers(n):
    i = 1
    cube_numbers = []
    while i * i * i <= n:
        cube_numbers.append(i * i * i)
        i += 1
    return cube_numbers

def get_fixed_number(n):
    i = 1
    fixed_number = []
    while i * i <= n:
        fixed_number.append(i * i)
        i += 1
    i = 1
    while i * i * i <= n:
        fixed_number.append(i * i * i)
        i += 1
    return fixed_number

def get_num_numbers(n):
    fixed_number = get_fixed_number(n)
    square_numbers = get_square_numbers(n)
    cube_numbers = get_cube_numbers(n)
    num_numbers = set(fixed_number + square_numbers + cube_numbers)
    # print(fixed_number, square_numbers, cube_numbers)
    # print(num_numbers)
    num_numbers = list(num_numbers)
    num_numbers.sort()
    # print(num_numbers)
    return len(num_numbers)

for _ in range(t):
    n = int(input())
    print(get_num_numbers(n))