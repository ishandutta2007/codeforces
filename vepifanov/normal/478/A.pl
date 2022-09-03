my @arr = split /\s+/, <>;
my @sum = 0;
$sum += $_ foreach @arr;
if ($sum % 5 == 0 and $sum > 0) {
    print $sum / 5, "\n";
} else {
    print -1;   
}