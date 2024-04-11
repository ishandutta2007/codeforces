$_ = <STDIN>; my ($a, $b) = split;

$st2 = 1;
$st2c = 0;
$ans = 0;
while($st2<=$b)
{
    $st3 = 1;
    while($st2 * $st3 <= $b)
    {
        if($st2 * $st3 >= $a)
        {
            $ans = $ans + 1;
        }
        $st3 = $st3 * 3;
    }
    $st2 = $st2 * 2;
}

print "$ans";