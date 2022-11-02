{$r-,q-,s-,i-,o+}
var
  res,tt,m,ss,ff,t,x:longint;
  up:boolean;
  function solve(ss,ff:longint;var up:boolean):longint;
    begin
      if (ss=ff)then begin
        solve:=0;
        exit;
      end;
      if (ss<ff)then begin
        if (up)
          then solve:=ff-ss
          else begin
            solve:=2*(ss-1)+ff-ss;
            up:=true;
          end;
        if (ff=m)then up:=false;
      end else begin
        if (not up)
          then solve:=ss-ff
          else begin
            solve:=2*(m-ss)+ss-ff;
            up:=false;
          end;
        if (ff=1)then up:=true;
      end;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(tt,m);
  while (tt>0)do begin
    dec(tt);
    read(ss,ff,t);
    if (ss=ff)then begin
      writeln(t);
      continue;
    end;
    x:=t div (m-1);
    if (x and 1=0)then up:=true else up:=false;
    x:=t mod (m-1);
    if (up)then x:=x+1 else x:=m-x;
    res:=solve(x,ss,up);
    res:=res+solve(ss,ff,up);
    writeln(t+res);
  end;
  close(output);close(input);
end.