<?php

    $str = trim(fgets(STDIN));
    $m = (int)fgets(STDIN);
    $len = strlen($str);
    
    $rem = 1;
    $now = 0;
    $ans = 1234567890;
    for ($i = 1; $i < $len; $i++)
    {
        $rem = $rem * 10 % $m;
    }
    for ($i = 0; $i < $len; $i++)
    {
        $now = ($now * 10 + $str[$i] - '0') % $m;
    }
    
    $ans = min($ans, $now);
    
    for ($i = 0; $i < $len; $i++)
    {
        $now = ((($now - $rem * ($str[$i] - '0')) % $m * 10 + $str[$i] - '0') % $m + $m) % $m;
        if ($str[($i + 1) % $len] != '0') $ans = min($ans, $now);
    }
    
    echo $ans + "\n";
?>