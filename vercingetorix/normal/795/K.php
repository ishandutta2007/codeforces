<?php
$fl =STDIN;
fscanf($fl , "%d\n", $n);
fscanf($fl , "%s", $a);
// printf("%s\n",$a);
$l = (int)0;
$ans = (string)"";
while($l<strlen($a)) {
    $r=$l+1;
    if($a[$l]=='a' or $a[$l]=='y' or $a[$l]=='o' or $a[$l]=='u' or $a[$l]=='i' or $a[$l]=='e') {
        while($r<strlen($a) and $a[$l]==$a[$r]) $r++;
    }
    // printf("%c",$a[$l]);
    $ans = $ans . $a[$l];
    if($a[$l] == 'e' and $r == $l+2) $ans = $ans . $a[$l];
    if($a[$l] == 'o' and $r == $l+2) $ans = $ans . $a[$l];
    $l=$r;
}
printf("%s\n",$ans);
?>