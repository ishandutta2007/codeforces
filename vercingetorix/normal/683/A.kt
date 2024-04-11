fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)

    if((x>a) || (y>a) || (x<0) || (y<0))  {
        print("2")
        return
    }
    if(x==a || y==a || x==0 || y==0) {
        print("1")
        return
    }
    print("0")
    return
}