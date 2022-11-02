{$r-,q-,s-,i-,o+}
const
  //FSUDLR
  rev:array[1..6]of longint=(1,2,5,6,4,3);
  perm:array[1..6,1..6]of longint=((1,2,3,4,5,6),
                                   (2,1,3,4,6,5),
                                   (3,4,2,1,5,6),
                                   (4,3,1,2,5,6),
                                   (5,6,3,4,2,1),
                                   (6,5,3,4,1,2));
                                   
var
  s:string;
  kr:longint;
  was:array[0..500]of boolean;
  r:array[0..5000]of string;
  procedure rec(x:longint;p:string);
    var
      j,q,i:longint;
      ns,ss,cr:string;
    begin  
      if (x>6)then begin
        cr:=#255;
        for i:=1 to 6 do begin  
          ss:='';
          for j:=1 to 6 do ss:=ss+' ';
          for j:=1 to 6 do ss[perm[i][j]]:=p[j];
          for j:=1 to 4 do begin
            if (ss<cr)then cr:=ss;
            ns:='';
            for q:=1 to 6 do ns:=ns+' ';
            for q:=1 to 6 do ns[rev[q]]:=ss[q];
            ss:=ns;
          end;
        end;
        i:=1;
        while (i<=kr)and(cr<>r[i])do inc(i);
        if (i>kr)then begin
          inc(kr);
          r[kr]:=cr;
        end;
        exit;
      end;
      for i:=1 to 6 do 
        if (not was[i])then begin
          was[i]:=true;
          rec(x+1,p+s[i]);
          was[i]:=false;
        end;
    end;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  readln(s);
  fillchar(was,sizeof(was),false);
  kr:=0;
  rec(1,'');
  writeln(kr);
  close(output);close(input);
end.